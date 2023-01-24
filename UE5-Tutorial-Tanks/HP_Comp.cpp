// Fill out your copyright notice in the Description page of Project Settings.


#include "HP_Comp.h"

// Sets default values for this component's properties
UHP_Comp::UHP_Comp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHP_Comp::BeginPlay()
{
	Super::BeginPlay();

	HP = MaxHP;
	
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHP_Comp::DMGTaken);
}


// Called every frame
void UHP_Comp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHP_Comp::DMGTaken(AActor *DamagedActor, float Damage, const UDamageType* DamageType, class AController* Instigator, AActor* DamageCauser)
{
	if (Damage <= 0.f) return;

	HP -= Damage;
	UE_LOG(LogTemp, Warning, TEXT("HP: %f"), HP);
}