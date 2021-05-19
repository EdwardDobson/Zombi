// Fill out your copyright notice in the Description page of Project Settings.

#include "BasePlay.h"

// Sets default values
ABasePlay::ABasePlay()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	RootComponent = Mesh;
	SpringArm->SetupAttachment(Mesh);
	Camera->SetupAttachment(SpringArm);
	Mesh->SetSimulatePhysics(true);
	MovementForce = 100000;

}

// Called when the game starts or when spawned
void ABasePlay::BeginPlay()
{
	Super::BeginPlay();
		MaxHealth = Health ;
}

// Called every frame
void ABasePlay::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Dead();
	if (!CurrentVelocity.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
		SetActorLocation(NewLocation);
	}
}

// Called to bind functionality to input
void ABasePlay::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveUp", this, &ABasePlay::MoveUp);
	InputComponent->BindAxis("MoveRight", this, &ABasePlay::MoveRight);
}
void ABasePlay::MoveUp(float _value)
{
	CurrentVelocity.X = FMath::Clamp(_value, -1.0f, 1.0f) * MovementForce;
}
void ABasePlay::MoveRight(float _value)
{
	CurrentVelocity.Y = FMath::Clamp(_value, -1.0f, 1.0f) * MovementForce;
}

void ABasePlay::IncreasePlayerHealth(float _value)
{
	Health += _value;
}
void ABasePlay::Damage(float _value)
{
	Health -= _value;
	if (Health <= 0)
	{
		Health = 50;
		Lives -= 1;

	}
}
void ABasePlay::Dead()
{

	if (Lives <= 0)
	{
		LevelName = FName(*UGameplayStatics::GetCurrentLevelName(this, true));
		
	}
}
