// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.h"
#include "Weapon.generated.h"

UCLASS()
class ALIZARIN_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	

	// function called when the mouse button is held down
	// for some weapons, this will fire a projectile or create a line trace that inflicts damage
	// for charge weapons, this can instead build a shot to be released by FireRelease
	UFUNCTION(BlueprintCallable, Category = "Weapon")
		virtual void FireHold(FVector origin, FVector direction);

	// called when player releases mouse
	// for charged weapons, this can fire a projectile
	// otherwise, can simulate semi-automatic weapon by resetting a large shot timer
	UFUNCTION(BlueprintCallable, Category = "Weapon")
		virtual void FireRelease(FVector origin, FVector direction);

	// time between shots called by FireHold
	// can be modified by attack speed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float shotDelay = 1.0f;

	float nextShotTime = 0.0f; // firing will set this to current time + shot delay
	bool CanFireNextShot();

	FDamageStruct MakeDamage(); // create a damage struct from the weapon's stats

	// the name of the weapon
	// weapons that are not unique will have prefixes and affixes associated to stat boosts
	// e.g. "Vicious Rocket Pod of Burning"
	// unique weapons will have their own name instead
	// e.g. "The Archon"
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		FString name = "Default Weapon";

	// describes any statistical traits of this weapon in text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		FString tooltip = "Default Weapon Tooltip";

	// extra flavor text, for explaining the purpose of the weapon or its origin
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		FString flavortext = "";

	// damage ranges for each type
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float physicalMin = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float physicalMax = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float heatMin = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float heatMax = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float coldMin = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float coldMax = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float electricMin = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float electricMax = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float chemicalMin = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float chemicalMax = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float voidMin = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float voidMax = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float critChance = 0.1f; // chance to apply critical bonus
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float critMult = 1.5f; // critical bonus multiplier
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float status = 0.1f; // chance to apply a status type
};
