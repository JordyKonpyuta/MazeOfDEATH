// Fill out your copyright notice in the Description page of Project Settings.


#include "Maze_Ruby.h"

#include "Maze_Player.h"
#include "Maze_PlayerController.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMaze_Ruby::AMaze_Ruby()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));

}

// Called when the game starts or when spawned
void AMaze_Ruby::BeginPlay()
{
	Super::BeginPlay();

	if (Cast<AMaze_Player>(GetWorld()->GetFirstPlayerController()->GetPawn()) != nullptr)
	{
		PlayerRef = Cast<AMaze_Player>(GetWorld()->GetFirstPlayerController()->GetPawn());
	}
	

	FTimerHandle ActivateHandle;
	GetWorld()->GetTimerManager().SetTimer(ActivateHandle, this, &AMaze_Ruby::SetIsAvailable, 2.5f, false);
}

// Called every frame
void AMaze_Ruby::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerRef != nullptr && bIsAvailable)
	{
		if (FVector::Distance(GetActorLocation(), PlayerRef->GetActorLocation()) <= 200.0f)
		{
			PlayerRef->PlayerController->CollectRubies();
			PlaySound();
			Destroy();
		}
	}

}

void AMaze_Ruby::SetIsAvailable()
{
	if (bIsAvailable)
	{
		SetActorHiddenInGame(false);
	}

	else
		SetActorHiddenInGame(true);
}

void AMaze_Ruby::PlaySound_Implementation()
{
}
