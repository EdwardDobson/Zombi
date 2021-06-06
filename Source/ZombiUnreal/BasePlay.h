// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GunWeapon.h"
#include "HealthPickup.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerFiring.h"
#include "DrawDebugHelpers.h"
#include "Macros.h"
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
		int Lives{ 3 };

	UPROPERTY(VisibleAnywhere)
		class UPlayerFiring* PlayerFiring;
	FName LevelName{ "Level1" };
	UPROPERTY(VisibleAnywhere)
	FVector CurrentVelocity;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float JumpValue{ 100000 };
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float JumpCooldownMax{ 3 };
	float JumpCooldownCurrent{ 0 };
	bool StartJumpCooldown;
	void MoveUp(float _value);
	void MoveRight(float _value);

	void JumpUp();
	void FireInput();
	void FireRelease();
	void ReloadInput();
	void IncreasePlayerHealth(float _value);
	void ChangeWeaponIndex(float _value);
	UFUNCTION(BlueprintCallable, Category = "Player")
		void Damage(float _value);
	UFUNCTION(BlueprintCallable, Category = "UI-Utility")
		int GetAmmoValueForUI();
	void Dead();
	void PickupWeaponInput();
	UFUNCTION(BlueprintCallable)
	void SetPickedUpWeapon(TSubclassOf<AGunWeapon> _weapon);
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Health{ 100 };
	float MaxHealth{ 100 };
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool OverWeapon;
	UPROPERTY(EditAnywhere, Category = "Weapon")
		TSubclassOf<AGunWeapon> PickedUpWeapon;
private:
	bool m_canJump{ true };
	bool m_shouldFire = false;
	bool m_shouldReload = false;
};
