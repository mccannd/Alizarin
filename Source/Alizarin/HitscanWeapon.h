// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Weapon.h"
#include "HitscanWeapon.generated.h"

/**
 * 
 */
UCLASS()
class ALIZARIN_API AHitscanWeapon : public AWeapon
{
	GENERATED_BODY()
	
	
public:
	// function called when left mouse button held down
	UFUNCTION(BlueprintCallable, Category = "Weapon")
		virtual void FireHold(FVector origin, FVector direction) override;

	// if false, stops at first collision. if true, pierces all in path
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		bool piercing = false;

	// number of shots fired in a single trigger pull, can create burst fire or shotgun
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		int32 numPellets = 1;

	// inaccuracy of the random, zero by default
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float spreadHalfArc = 0.0f;

	// editable range of the hitscan weapon
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float range = 1500.0f;

	// called by FireHold for each pellet fired, handles line tracing
	void fireSinglePellet(
		FVector origin,
		FVector direction,
		ECollisionChannel& channel,
		FCollisionQueryParams& params
		);
};
