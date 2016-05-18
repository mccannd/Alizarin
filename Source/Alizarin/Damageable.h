// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Damageable.generated.h"


// defines the different types of damage in Alizarin
// also encapsulates other properties of the weapon, such as critical chance
USTRUCT(BlueprintType)
struct FDamageStruct
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		int32 physicalDamage;

	// heat, inflicts burning status
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		int32 heatDamage;

	// cold, inflicts stacking slow to a full freeze
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		int32 coldDamage;

	// electric can spark to nearby enemies with an interrupting effect
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		int32 electricDamage;

	// chemical can corrode armor and slightly increase damage taken
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		int32 chemicalDamage;

	// spooky space magic, tentatively destabilizes / deals more damage to lower health enemies
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		int32 voidDamage;

	// the chance that this damage will benefit from a critical bonus
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		float criticalChance;

	// intensity of the critical bonus, 2 should be average
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		float criticalMultiplier;

	// chance to inflict a status based on the type of damage dealt, NYI
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		float statusChance;
};

// simple struct to encapsulate resistances to each damage type
USTRUCT(BlueprintType)
struct FResistanceStruct
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		float physicalResist;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		float heatResist;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		float coldResist;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		float electricResist;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		float chemicalResist;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		float voidResist;

};

UINTERFACE()
class UDamageable : public UInterface
{
	GENERATED_UINTERFACE_BODY()


};

class IDamageable
{
	GENERATED_IINTERFACE_BODY()

public:
		UFUNCTION(BlueprintCallable, Category = "Damageable")
		virtual void TakeDamage(FDamageStruct damage);
};
