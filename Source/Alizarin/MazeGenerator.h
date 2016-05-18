// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "RoomCellClass.h"
#include "MazeGenerator.generated.h"


struct RoomRow {
	TArray<RoomCellStruct> roomColumns;
};

UCLASS()
class ALIZARIN_API AMazeGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMazeGenerator();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		TArray< TSubclassOf<ARoom> > Room_1_Door;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		TArray< TSubclassOf<ARoom> > Room_2_Doors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		TArray< TSubclassOf<ARoom> > Room_3_Doors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
		TArray< TSubclassOf<ARoom> > Room_4_Doors;

	UFUNCTION(BlueprintCallable, Category = "MazeGenerator")
		void GenerateMaze(int32 x, int32 y, int32 start_x, int32 start_y);

	void GenerateCell(int32 x, int32 y); //recursively generate a cell of the maze

private:
	
	TArray<RoomRow> all_rooms;
	int32 cells_x;
	int32 cells_y;

	int32 origin_x;
	int32 origin_y;
	
	float cell_length = 2000.0f;
};
