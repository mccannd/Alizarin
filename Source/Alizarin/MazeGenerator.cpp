// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceDiablo.h"
#include "MazeGenerator.h"


// Sets default values
AMazeGenerator::AMazeGenerator()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMazeGenerator::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMazeGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMazeGenerator::GenerateMaze(int32 x, int32 y, int32 start_x, int32 start_y)
{
	cells_x = x;
	cells_y = y;
	// fill with baseline, empty rows
	for (int i = 0; i < x; i++) {
		RoomRow newRow = RoomRow();
		for (int j = 0; j < y; j++) {
			RoomCellStruct newRoom = RoomCellStruct();
			newRow.roomColumns.Add(newRoom);
		}
		all_rooms.Add(newRow);

	}
	// begin generating maze
	origin_x = start_x;
	origin_y = start_y;
	GenerateCell(start_x, start_y);

}

void rotateCW(bool& n, bool& e, bool& s, bool& w)
{
	bool t = w;
	w = s;
	s = e;
	e = n;
	n = t;
}

// check if a room fits into its position,
// given the status of adjacent doors
// given whether it is trying to put a door at each side
bool roomFits(DoorwayStatus adj_n, 
	DoorwayStatus adj_e, 
	DoorwayStatus adj_s, 
	DoorwayStatus adj_w, 
	bool n, bool e, bool s, bool w)
{
	// false if trying to put a door in a blocked location
	if (n && adj_n == DoorwayStatus::BLOCKED) return false;
	if (e && adj_e == DoorwayStatus::BLOCKED) return false;
	if (s && adj_s == DoorwayStatus::BLOCKED) return false;
	if (w && adj_w == DoorwayStatus::BLOCKED) return false;


	// false if not putting a door in a required location
	if (!n && adj_n == DoorwayStatus::REQUIRED) return false;
	if (!e && adj_e == DoorwayStatus::REQUIRED) return false;
	if (!s && adj_s == DoorwayStatus::REQUIRED) return false;
	if (!w && adj_w == DoorwayStatus::REQUIRED) return false;
	
	return true;
}

void AMazeGenerator::GenerateCell(int32 x, int32 y) {
	// return if going out of bounds
	if (x >= all_rooms.Num()) return;
	if (y >= all_rooms[0].roomColumns.Num()) return;
	
	RoomCellStruct currentCell = all_rooms[x].roomColumns[y];

	if (currentCell.initialized) return; // if this room was already generated, go back
	
	// status of each adjacent cell: blocked (cannot connect) required (must) open (can)
	DoorwayStatus adj_w, adj_e, adj_s, adj_n; 

	if (x <= 0) adj_e = DoorwayStatus::BLOCKED;
	else adj_e = all_rooms[x - 1].roomColumns[y].west;

	if (x >= cells_x - 1) adj_w = DoorwayStatus::BLOCKED;
	else adj_w = all_rooms[x + 1].roomColumns[y].east;

	if (y <= 0) adj_s = DoorwayStatus::BLOCKED;
	else adj_s = all_rooms[x].roomColumns[y - 1].north;

	if (y >= cells_y - 1) adj_n = DoorwayStatus::BLOCKED;
	else adj_n = all_rooms[x].roomColumns[y + 1].south;

	int min = 0;
	if (adj_s == DoorwayStatus::REQUIRED) min++;
	if (adj_n == DoorwayStatus::REQUIRED) min++;
	if (adj_e == DoorwayStatus::REQUIRED) min++;
	if (adj_w == DoorwayStatus::REQUIRED) min++;
	int max = 4;
	if (adj_s == DoorwayStatus::BLOCKED) max--;
	if (adj_n == DoorwayStatus::BLOCKED) max--;
	if (adj_e == DoorwayStatus::BLOCKED) max--;
	if (adj_w == DoorwayStatus::BLOCKED) max--;

	int num_doorways = FMath::RandRange(min, max);
	if (num_doorways == 0) num_doorways++;

	// for debugging
	UE_LOG(LogTemp, Warning, TEXT("Blocked Directions: %s%s%s%s"),
		adj_n == DoorwayStatus::BLOCKED ? TEXT("North ") : TEXT(""),
		adj_e == DoorwayStatus::BLOCKED ? TEXT("East ") : TEXT(""), 
		adj_s == DoorwayStatus::BLOCKED ? TEXT("South ") : TEXT(""), 
		adj_w == DoorwayStatus::BLOCKED ? TEXT("West ") : TEXT(""));
	UE_LOG(LogTemp, Warning, TEXT("Required Directions: %s%s%s%s"),
		adj_n == DoorwayStatus::REQUIRED ? TEXT("North ") : TEXT(""),
		adj_e == DoorwayStatus::REQUIRED ? TEXT("East ") : TEXT(""),
		adj_s == DoorwayStatus::REQUIRED ? TEXT("South ") : TEXT(""),
		adj_w == DoorwayStatus::REQUIRED ? TEXT("West") : TEXT(""));
	UE_LOG(LogTemp, Warning, TEXT("Selected %d number of doorways"), num_doorways);

	// select a random room with this number of doorways
	int num_room_of_type;
	if (num_doorways == 1) num_room_of_type = Room_1_Door.Num();
	else if (num_doorways == 2) num_room_of_type = Room_2_Doors.Num();
	else if (num_doorways == 3) num_room_of_type = Room_3_Doors.Num();
	else num_room_of_type = Room_4_Doors.Num();

	TArray<int> index_selector; // make the set of possible indices for rooms of this size
	for (int i = 0; i < num_room_of_type; i++) index_selector.Add(i);

	// orientation of the rooms we select
	bool n = false;
	bool e = false;
	bool s = false;
	bool w = false;
	bool success = false;
	int tries = 0;

	while (index_selector.Num() > 0 && tries < 5) {
		tries++;
		// select a random room that hasnt been tried yet
		int selected = FMath::RandRange(0, index_selector.Num() - 1); 
		selected = index_selector[selected];
		ARoom* room;
		if (num_doorways == 1)  room = Room_1_Door[selected]->GetDefaultObject<ARoom>();
		else if (num_doorways == 2) room = Room_2_Doors[selected]->GetDefaultObject<ARoom>();
		else if (num_doorways == 3) room = Room_3_Doors[selected]->GetDefaultObject<ARoom>();
		else room = Room_4_Doors[selected]->GetDefaultObject<ARoom>();

		n = room->north;
		e = room->east;
		s = room->south;
		w = room->west;
		
		for ( int rotations = 0; rotations < 4; rotations++) {
			UE_LOG(LogTemp, Warning, TEXT("Trying rotation %d at %d, %d: %s%s%s%s"),
				rotations, x, y, 
				n ? TEXT("North ") : TEXT(""),
				e ? TEXT("East ") : TEXT(""), 
				s ? TEXT("South ") : TEXT(""), 
				w ? TEXT("West ") : TEXT(""));

			if (roomFits(adj_n, adj_e, adj_s, adj_w, n, e, s, w)) {
				success = true;
				FVector location = FVector((x - origin_x) * cell_length, 
					(y - origin_y) * cell_length, 0);
				FRotator rotation = FRotator(0, rotations * 90.0f, 0);
				FTransform transform = FTransform(rotation, location);

				currentCell.initialized = true;

				// spawn the room in this position
				UWorld* const World = GetWorld();
				if (World) {
					if (room) { 
						ARoom* spawned_room = World->SpawnActor<ARoom>(room->GetActorClass(), transform);
						currentCell.cell_room = spawned_room;
					}
					else { UE_LOG(LogTemp, Warning, TEXT("Room is nullptr")); }
				}
				else { UE_LOG(LogTemp, Warning, TEXT("World is nullptr")); }

				
				//mark the doorways of this cell for the next cells
				if (n) currentCell.north = DoorwayStatus::REQUIRED;
				else currentCell.north = DoorwayStatus::BLOCKED;
				if (e) currentCell.east = DoorwayStatus::REQUIRED;
				else currentCell.east = DoorwayStatus::BLOCKED;
				if (s) currentCell.south = DoorwayStatus::REQUIRED;
				else currentCell.south = DoorwayStatus::BLOCKED;
				if (w) currentCell.west = DoorwayStatus::REQUIRED;
				else currentCell.west = DoorwayStatus::BLOCKED;

				all_rooms[x].roomColumns[y] = currentCell;

				break;
			}
			rotateCW(n, e, s, w);
		}
		if (success) break;
		index_selector.Remove(selected); // room placement failed, take this choice out of the list and move on
	}

	// generate new cells from each doorway placed
	if (success) {
		if (n) GenerateCell(x, y + 1);
		if (e) GenerateCell(x - 1, y);
		if (s) GenerateCell(x, y - 1);
		if (w) GenerateCell(x + 1, y);
	}
	else UE_LOG(LogTemp, Warning, TEXT("Cell generation failed"));
	

}