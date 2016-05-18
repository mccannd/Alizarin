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

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		virtual void FireHold(FVector origin, FVector direction);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		virtual void FireRelease(FVector origin, FVector direction);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float physicalMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float physicalMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float heatMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float heatMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float coldMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float coldMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float electricMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float electricMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float chemicalMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float chemicalMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float voidMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float voidMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float critChance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float critMult;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		float status;
};
