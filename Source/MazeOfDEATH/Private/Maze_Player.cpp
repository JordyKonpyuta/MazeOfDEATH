// Fill out your copyright notice in the Description page of Project Settings.


#include "Maze_Player.h"

#include "Maze_Monster.h"
#include "Maze_PlayerController.h"

// Sets default values
AMaze_Player::AMaze_Player()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMaze_Player::BeginPlay()
{
	Super::BeginPlay();

	if (Cast<AMaze_PlayerController>(GetController()))
	{
		PlayerController = Cast<AMaze_PlayerController>(GetController());
		PlayerController->PlayerRef = this;
	}
	
}

// Called every frame
void AMaze_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float Distance = FVector::Distance(GetActorLocation(), PlayerController->MonsterRef->GetActorLocation());

	if (Distance < 100)
	{
		Fear = EFearLevel::High;
	}
	else if (Distance < 200)
	{
		Fear = EFearLevel::Medium;
	}
	else
	{
		Fear = EFearLevel::Low;
	}

}

// Called to bind functionality to input
void AMaze_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMaze_Player::MoveForward(float Value)
{
	FHitResult Hit;
	FVector Start = GetActorLocation();
	FVector End = Start + GetActorForwardVector() * Value * 100;

	FCollisionQueryParams TraceParams;
	TraceParams.AddIgnoredActor(this);

	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, TraceChannel, TraceParams);

	if (!Hit.bBlockingHit)
	{
		SetActorLocation(GetActorLocation() + GetActorForwardVector() * Value * 100);
	}
}

void AMaze_Player::TurnAround(float Ratio)
{
	SetActorRotation(GetActorRotation() + FRotator3d(0,0,90*Ratio));
}

