// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceDiablo.h"
#include "BaseCharacter.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	resistances.physicalResist = 0.2;
	
	
}

// Called every frame
void ABaseCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}
void ABaseCharacter::CalculateHealth(float delta) {
	Health += delta;
	if (Health <= 0) {
		Health = 0; isDead = true;
	}
	else isDead = false;
}

void ABaseCharacter::CalculateDamage(FDamageStruct damage) {
	float crit = FMath::FRand();
	float critmult = crit < damage.criticalChance ? damage.criticalMultiplier : 1.0f;

	int calcdamage = 0;
	calcdamage += damage.physicalDamage * (1.0f - resistances.physicalResist);
	calcdamage += damage.heatDamage * (1.0f - resistances.heatResist);
	calcdamage += damage.coldDamage * (1.0f - resistances.coldResist);
	calcdamage += damage.electricDamage * (1.0f - resistances.electricResist);
	calcdamage += damage.chemicalDamage * (1.0f - resistances.chemicalResist);
	calcdamage += damage.voidDamage * (1.0f - resistances.voidResist);

	calcdamage *= critmult;
	CalculateHealth(-calcdamage);
}

#if WITH_EDITOR
void ABaseCharacter::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	isDead = false;
	Health = 100;
	Super::PostEditChangeProperty(PropertyChangedEvent);

}
#endif

