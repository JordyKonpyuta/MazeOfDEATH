// Fill out your copyright notice in the Description page of Project Settings.


#include "Maze_Player.h"

#include "Maze_Monster.h"
#include "Maze_PlayerController.h"
#include "Maze_Ruby.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AMaze_Player::AMaze_Player()
{
	if (Cast<AMaze_PlayerController>(GetController()))
	{
		PlayerController = Cast<AMaze_PlayerController>(GetController());
		PlayerController->PlayerRef = this;
		UE_LOG( LogTemp, Warning, TEXT("PlayerController is set") );
	}

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT ("CameraComponent"));
	CameraComponent->SetupAttachment(CapsuleComponent);
	CameraComponent->SetRelativeLocation(FVector(-10, 0, 0));
	
	bUseControllerRotationYaw = true;
	CameraComponent->bUsePawnControlRotation = true;

}

// Called when the game starts or when spawned
void AMaze_Player::BeginPlay()
{
	Super::BeginPlay();

	Fear = EFearLevel::Low;

	GetWorld()->GetTimerManager().SetTimer(InitializationTimer, this, &AMaze_Player::InitializePlayer, 2.0f, false);
	GetWorld()->GetTimerManager().SetTimer( FearTimer, this, &AMaze_Player::CheckFearLevel, 0.5f, true );
	
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
	FVector End = Start + CameraComponent->GetForwardVector() * Value * 8.5;

	FCollisionQueryParams TraceParams;
	TraceParams.AddIgnoredActor(this);

	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, TraceChannel, TraceParams);

	if (!Hit.bBlockingHit)
	{
		SetActorLocation(GetActorLocation() + CameraComponent->GetForwardVector() * Value * 8.5, false, nullptr, ETeleportType::ResetPhysics);
	}
}

void AMaze_Player::TurnAround(float Ratio)
{

	// Add Local Rotation
	//SetActorRotation(FRotator(0, GetActorRotation().Yaw + (90 * Ratio), 0));

	// SetControlRotation
	GetController()->SetControlRotation(FRotator(0, GetController()->GetControlRotation().Yaw + (90 * Ratio), 0));
}

void AMaze_Player::InitializePlayer()
{
}

void AMaze_Player::CheckFearLevel()
{
	if(PlayerController->IsValidLowLevel() && PlayerController->MonsterRef->IsValidLowLevel())
	{
		float Distance = FVector::Distance(GetActorLocation(), PlayerController->MonsterRef->GetActorLocation());
		UE_LOG( LogTemp, Warning, TEXT("Distance: %f"), Distance );

		if (Distance < 900)
		{
			Fear = EFearLevel::High;
			UpdateUI();
		}
		else if (Distance < 1300)
		{
			Fear = EFearLevel::Medium;
			UpdateUI();
		}
		else
		{
			Fear = EFearLevel::Low;
			UpdateUI();
		}
	}

	else GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("PlayerController or MonsterRef is not valid"));
}

void AMaze_Player::UpdateUI_Implementation()
{
}

