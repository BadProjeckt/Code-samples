// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	class ATank* Tank;

private:
	UPROPERTY(EditDefaultsOnly,Category="Combat")
	float FireRange;

	FTimerHandle FireRateTimerHandle;
	float FireRate = 1.f;
	void CheckFireCondition();

	bool InFireRange();
};
