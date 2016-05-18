// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Room.h"


// enumeration for our generator:
// BLOCKED means there is a wall here and we cant connect in this direction
// OPEN means there isn't anything here and we have a chance to connect
// REQUIRED means there is a doorway here which must be resolved with a connection
enum DoorwayStatus { BLOCKED, OPEN, REQUIRED };

struct RoomCellStruct {

	RoomCellStruct() {}

	// All doorway boundaries are open on initialization
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
