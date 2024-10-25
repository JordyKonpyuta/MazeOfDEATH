// Fill out your copyright notice in the Description page of Project Settings.


#include "Maze_Ruby.h"

#include "Maze_Player.h"
#include "Maze_PlayerController.h"
#include "Components/BoxComponent.h"

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
	
}

// Called every frame
void AMaze_Ruby::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
