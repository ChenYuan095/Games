// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCore/Weapon_Base.h"
#include"Components/SkeletalMeshComponent.h"
#include"Components/SceneComponent.h"
// Sets default values
AWeapon_Base::AWeapon_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	Weapon->SetupAttachment(GetRootComponent());

	PuzzlePosition = CreateDefaultSubobject<USceneComponent>(TEXT("Puzzle"));
	PuzzlePosition->SetupAttachment(Weapon);
}

// Called when the game starts or when spawned
void AWeapon_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

