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
	PlayerFiring = CreateDefaultSubobject<UPlayerFiring>("PlayerFiring");
	RootComponent = Mesh;
	SpringArm->SetupAttachment(Mesh);
	Camera->SetupAttachment(SpringArm);
	AddOwnedComponent(PlayerFiring);
	PlayerFiring->SetWorld(GetWorld());
	MovementForce = 100000;

}

// Called when the game starts or when spawned
void ABasePlay::BeginPlay()
{
	Super::BeginPlay();
	MaxHealth = Health;

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
	if (m_shouldFire)
	{
		PlayerFiring->Fire(GetActorLocation(),GetActorRotation());
	}
}

// Called to bind functionality to input
void ABasePlay::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveUp", this, &ABasePlay::MoveUp);
	InputComponent->BindAxis("MoveRight", this, &ABasePlay::MoveRight);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ABasePlay::JumpUp);
	InputComponent->BindAction("Fire", IE_Pressed, this, &ABasePlay::FireInput);
	InputComponent->BindAction("Fire", IE_Released, this, &ABasePlay::FireRelease);
	InputComponent->BindAction("Reload", IE_Pressed, this, &ABasePlay::ReloadInput);
}
void ABasePlay::MoveUp(float _value)
{
	CurrentVelocity.X = FMath::Clamp(_value, -1.0f, 1.0f) * MovementForce;
}
void ABasePlay::MoveRight(float _value)
{
	CurrentVelocity.Y = FMath::Clamp(_value, -1.0f, 1.0f) * MovementForce;
}
void ABasePlay::FireInput()
{
	PlayerFiring->SetShouldFire(true);
}
void ABasePlay::FireRelease()
{
	PlayerFiring->SetShouldFire(false);
}
void ABasePlay::ReloadInput()
{
	PlayerFiring->SetShouldReload(true);
}
void ABasePlay::JumpUp()
{
	m_canJump = true;
	FVector jumpDir = FVector(0, 0, JumpValue);
	Mesh->AddImpulse(jumpDir, "", false);
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
int ABasePlay::GetAmmoValueForUI()
{
	return PlayerFiring->Ammo;
}
void ABasePlay::Dead()
{
	if (Lives <= 0)
	{
		LevelName = FName(*UGameplayStatics::GetCurrentLevelName(this, true));
	}
}