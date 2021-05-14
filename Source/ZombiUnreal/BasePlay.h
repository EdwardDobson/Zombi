// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "HealthPickup.h"
#include "Kismet/GameplayStatics.h"
#include "BasePlay.generated.h"


UCLASS()
class ZOMBIUNREAL_API ABasePlay : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePlay();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCameraComponent* Camera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementForce;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Lives;

	FName LevelName{"Level1"};
	FVector CurrentVelocity;
	void MoveUp(float _value);
	void MoveRight(float _value);
	void IncreasePlayerHealth(float _value);
	UFUNCTION(BlueprintCallable, Category = "Player")
	void Damage(float _value);
		void Dead();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Health;
	float MaxHealth;
};
