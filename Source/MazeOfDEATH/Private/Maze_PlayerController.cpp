// Fill out your copyright notice in the Description page of Project Settings.


#include "Maze_PlayerController.h"

void AMaze_PlayerController::CollectRubies()
{
	RubiesCount++;
	UpdateUI();
}

void AMaze_PlayerController::UpdateUI_Implementation()
{
}
