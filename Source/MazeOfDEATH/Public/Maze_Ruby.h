// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Maze_Ruby.generated.h"

class AMaze_Player;

UCLASS()
class MAZEOFDEATH_API AMaze_Ruby : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMaze_Ruby();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	class UBoxComponent* CollisionBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsAvailable = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	AMaze_Player* PlayerRef;

	UFUNCTION()
	void SetIsAvailable();

	UFUNCTION(BlueprintNativeEvent)
	void PlaySound();

};
