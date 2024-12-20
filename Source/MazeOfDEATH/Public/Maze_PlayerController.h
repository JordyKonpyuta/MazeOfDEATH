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
class AMaze_Ruby;

UCLASS()
class MAZEOFDEATH_API AMaze_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RubiesCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NumberOfRubiesToCollect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AMaze_Monster* MonsterRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AMaze_Player* PlayerRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Timer = 30;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AMaze_Ruby*> Rubies;

	UFUNCTION(BlueprintCallable)
	void SelectRubies();

	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable, Category = "PlayerController")
	void CollectRubies();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "PlayerController")
	void UpdateUI();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "PlayerController")
	void GameOver();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "PlayerController")
	void GameWon();
	
};
