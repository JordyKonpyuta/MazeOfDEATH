// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Maze_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MAZEOFDEATH_API UMaze_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CandidateNumber = 0;
	
};
