// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"


USTRUCT(BlueprintType)
struct FDamageStruct
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		int32 physicalDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		int32 heatDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		int32 coldDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		int32 electricDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		int32 chemicalDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		int32 voidDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		float criticalChance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		float criticalMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShowInfo)
		float statusChance;
};

UCLASS()
class ALIZARIN_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
