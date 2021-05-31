// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Bullet/Bullet.h"
#include "BasePlay.h"
#include "Kismet/KismetMathLibrary.h"
#include "GunWeapon.h"
#include "Macros.h"
#include "PlayerFiring.generated.h"


/*
Handles both the firing and reloading
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZOMBIUNREAL_API UPlayerFiring : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerFiring();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Fire();
	void Reloading();
	void SetWorld(UWorld* _world, AActor* _player);
	void SwitchWeapon();
	void SetWeaponValues(TSubclassOf<AGunWeapon> _otherWeapon);


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Ammo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CurrentRateOfFire;
	UPROPERTY(EditAnywhere)
		float CurrentReloadRate;
	UPROPERTY(EditAnywhere, Category = "Bullet")
		TSubclassOf<ABullet> Bullet;
	UWorld* World;
	AActor* Player;
	FVector PlayerPos;
	UPROPERTY(EditAnywhere, Category = "Weapon")
		TSubclassOf<AGunWeapon> WeaponOne;
	UPROPERTY(EditAnywhere, Category = "Weapon")
		TSubclassOf<AGunWeapon> WeaponTwo;
	UPROPERTY(VisibleAnyWhere)
		int WeaponIndex;
	UPROPERTY(EditAnywhere, Category = "Weapon")
		TSubclassOf<AGunWeapon> m_currentWeapon;
#pragma region Getters

#pragma endregion
#pragma region Setters
	bool SetShouldReload(bool _state)
	{
	return	m_shouldReload = _state;
	}
	bool SetShouldFire(bool _state)
	{
		return	m_shouldFire = _state;
	}
#pragma endregion

private: 
	bool m_shouldReload;
	bool m_shouldFire;

};
