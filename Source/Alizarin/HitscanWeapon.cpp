// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceDiablo.h"
#include "HitscanWeapon.h"

// gets a random direction with a bias towards the center
FVector getRandomSpreadDirection(float spreadHalfArc, FVector& direction, bool biased = false)
{
	// if it's not biased just make a uniformly random rotation
	if (!biased) return direction.RotateAngleAxis(FMath::FRandRange(-spreadHalfArc, spreadHalfArc), FVector(0, 0, 1));

	// get random (not uniform) point in circle
	float randomArc = FMath::FRandRange(0, 360);
	FVector randomRad = FVector(FMath::FRandRange(0, spreadHalfArc) / 90.0f, 0, 0);
	FVector randomCirclePoint = randomRad.RotateAngleAxis(randomArc, FVector(0, 0, 1));
	// project point from circle onto line, deviation from 0 x coordinate is angle
	float biasedAngle = randomCirclePoint.X * 90.0f;
	return direction.RotateAngleAxis(biasedAngle, FVector(0, 0, 1));
}

FVector getTraceEnd(FVector start, FVector dir, float dist, float spread = 0.0f)
{
	if (FMath::IsNearlyZero(spread)) return start + dist * dir;
	else return start + dist * getRandomSpreadDirection(spread, dir);
}

// TODO: muzzle flash sprite
// TODO: beam along trace
// TODO: impact sprite
// TODO: sounds
void AHitscanWeapon::fireSinglePellet(
	FVector origin,
	FVector direction, 
	ECollisionChannel& channel,
	FCollisionQueryParams& params)
{
	// get line trace endpoint for this pellet
	FVector end = getTraceEnd(origin, direction, range, spreadHalfArc);

	if (!piercing) {
		// if the weapon is single target, do a single trace
		FHitResult collision = FHitResult(ForceInit);
		GetWorld()->LineTraceSingle(collision, origin, end, channel, params);

		// inflict damage if collided with damageable actor
		if (collision.GetActor() != NULL) {
			if (collision.Actor->GetClass()->ImplementsInterface(UDamageable::StaticClass())) {
				IDamageable* obj = InterfaceCast<IDamageable>(collision.GetActor());
				obj->TakeDamage(MakeDamage());
			}
		}
	}
	else {
		// otherwise do a multiline trace
		TArray<FHitResult> collisions;
		GetWorld()->LineTraceMulti(collisions, origin, end, channel, params);

		// TODO: make obstructions that interrupt trace since results are sorted
		for (FHitResult col : collisions) {
			if (col.GetActor() != NULL) {
				if (col.GetActor()->GetClass()->ImplementsInterface(UDamageable::StaticClass())) {
					IDamageable* obj = InterfaceCast<IDamageable>(col.GetActor());	
					obj->TakeDamage(MakeDamage());
				}
			}
		}
	}
}

// TODO: delay for burst fire weapons
void AHitscanWeapon::FireHold(FVector origin, FVector direction)
{
	if (!CanFireNextShot()) return;
	// initialize parameters for line trace
	ECollisionChannel channel = ECC_WorldDynamic;
	FCollisionQueryParams params(false);

	for (int pellet = 0; pellet < numPellets; pellet++) {
		// TODO: create timer to simulate burst fire
		fireSinglePellet(origin, direction, channel, params);
	}

	// set the next shot timer
	nextShotTime = GetWorld()->TimeSeconds + shotDelay;
}


