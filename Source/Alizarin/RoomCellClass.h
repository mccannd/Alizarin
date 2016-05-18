// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Room.h"



enum DoorwayStatus { BLOCKED, OPEN, REQUIRED };
/**
 * 
 */

struct RoomCellStruct {

	RoomCellStruct() {}

	// for the generator to see where it can, must, and cannot connect
	DoorwayStatus north = OPEN;
	DoorwayStatus south = OPEN;
	DoorwayStatus east = OPEN;
	DoorwayStatus west = OPEN;

	bool initialized = false; // whether the maze has finished its work on this cell

	ARoom* cell_room; // reference to room spawned inside this cell

};

class ALIZARIN_API RoomCellClass
{

public:
	RoomCellClass();
	~RoomCellClass();

};
