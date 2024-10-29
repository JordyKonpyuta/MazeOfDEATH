// Fill out your copyright notice in the Description page of Project Settings.


#include "Maze_PlayerController.h"

#include "Maze_Player.h"
#include "Maze_Ruby.h"

void AMaze_PlayerController::SelectRubies()
{
	for (int i = 0; i < 10; i++)
	{
		int Count = FMath::RandRange(0, Rubies.Num());
		if (Rubies.IsValidIndex(Count) && Rubies[Count] != nullptr)
		{
			Rubies[Count]->bIsAvailable = true;
			Rubies.RemoveAt(Count);
		}
	}
}

void AMaze_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (AMaze_Player* MazePlayer = Cast<AMaze_Player>(GetPawn()))
	{
		PlayerRef = MazePlayer;
		PlayerRef->PlayerController = this;
	}

	FTimerHandle RubyTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(RubyTimerHandle, this, &AMaze_PlayerController::SelectRubies, 2.0f, false);
	
}

void AMaze_PlayerController::CollectRubies()
{
	RubiesCount++;
	UpdateUI();
	if (RubiesCount == 10)
		GameWon();
}

void AMaze_PlayerController::GameWon_Implementation()
{
}

void AMaze_PlayerController::GameOver_Implementation()
{
}

void AMaze_PlayerController::UpdateUI_Implementation()
{
}
