// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Room.h"
#include "RoomCell.generated.h"

enum DoorwayStatusDeprecated {ZIP, ZOP, ZOOBITYBOP};

UCLASS()
class ALIZARIN_API ARoomCell : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARoomCell();
	/*
	// for the generator to see where it can, must, and cannot connect
	DoorwayStatus north = OPEN;
	DoorwayStatus south = OPEN;
	DoorwayStatus east = OPEN;
	DoorwayStatus west = OPEN;
	*/

	bool initialized = false; // whether the maze has finished its work on this cell

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	ARoom* cell_room; // reference to room spawned inside this cell

	
	
};
