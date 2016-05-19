// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceDiablo.h"
#include "Weapon.h"


// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AWeapon::FireHold(FVector origin, FVector direction)
{
	// does nothing since this is basically an interface
}

void AWeapon::FireRelease(FVector origin, FVector direction)
{
	// does nothing since this is basically an interface
}

bool AWeapon::CanFireNextShot()
{
	return GetWorld()->TimeSeconds >= nextShotTime;
}

FDamageStruct AWeapon::MakeDamage()
{
	FDamageStruct damage = FDamageStruct();
	damage.criticalChance = critChance;
	damage.criticalMultiplier = critMult;
	damage.statusChance = status;
	damage.physicalDamage = FMath::FRandRange(physicalMin, physicalMax);
	damage.heatDamage = FMath::FRandRange(heatMin, heatMax);
	damage.coldDamage = FMath::FRandRange(coldMin, coldMax);
	damage.electricDamage = FMath::FRandRange(electricMin, electricMax);
	damage.heatDamage = FMath::FRandRange(heatMin, heatMax);
	damage.heatDamage = FMath::FRandRange(voidMin, voidMax);
	return damage;
}
