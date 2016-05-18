// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Room.generated.h"

UCLASS()
class ALIZARIN_API ARoom : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARoom();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Room")
		bool north = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Room")
		bool south = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Room")
		bool east = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Room")
		bool west = false;
	
};
