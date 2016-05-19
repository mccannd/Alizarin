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

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		virtual void FireHold(FVector origin, FVector direction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		bool singleTarget = true;
};
