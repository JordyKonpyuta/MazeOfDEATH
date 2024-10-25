// Fill out your copyright notice in the Description page of Project Settings.


#include "Maze_PlayerController.h"

#include "Maze_Player.h"

void AMaze_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (AMaze_Player* MazePlayer = Cast<AMaze_Player>(GetPawn()))
	{
		PlayerRef = MazePlayer;
		PlayerRef->PlayerController = this;
	}
}

void AMaze_PlayerController::CollectRubies()
{
	RubiesCount++;
	UpdateUI();
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
