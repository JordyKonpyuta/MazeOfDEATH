// Fill out your copyright notice in the Description page of Project Settings.


#include "Maze_Monster.h"

#include "Maze_Player.h"
#include "Maze_PlayerController.h"

// Sets default values
AMaze_Monster::AMaze_Monster()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMaze_Monster::BeginPlay()
{
	Super::BeginPlay();

	// Get the player controller
	if (AMaze_PlayerController* MazePlayerController = Cast<AMaze_PlayerController>(GetWorld()->GetFirstPlayerController()))
	{
		MazePlayerController->MonsterRef = this;
		PlayerRef = Cast<AMaze_Player>(MazePlayerController->GetPawn());
	}
}

// Called every frame
void AMaze_Monster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerRef != nullptr)
	{
		if (FVector::Distance(GetActorLocation(), PlayerRef->GetActorLocation()) <= 200.0f)
		{
			PlayerRef->PlayerController->GameOver();
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Oskour"));
		}
	}

}

// Called to bind functionality to input
void AMaze_Monster::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

