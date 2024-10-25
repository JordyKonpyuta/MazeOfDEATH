// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Maze_PlayerController.generated.h"

/**
 * 
 */

class AMaze_Monster;
class AMaze_Player;

UCLASS()
class MAZEOFDEATH_API AMaze_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RubiesCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NumberOfRubiesToCollect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AMaze_Monster* MonsterRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AMaze_Player* PlayerRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Timer = 30;

	void BeginPlay();
	UFUNCTION(BlueprintCallable, Category = "PlayerController")
	void CollectRubies();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "PlayerController")
	void UpdateUI();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "PlayerController")
	void GameOver();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "PlayerController")
	void GameWon();
	
};
