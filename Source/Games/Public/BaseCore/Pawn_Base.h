// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Pawn_Base.generated.h"

class USkeletalMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class USceneComponent;
class UCapsuleComponent;
UCLASS()
class GAMES_API APawn_Base : public APawn
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere,Category=Mesh)
	USkeletalMeshComponent* PlayerMesh;
	UPROPERTY(VisibleAnywhere, Category = Mesh)
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category = Mesh)
	UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere, Category = Mesh)
	USkeletalMeshComponent* Gun;

	UPROPERTY(VisibleAnywhere, Category = Mesh)
	UCapsuleComponent* Capsule;

public:
	// Sets default values for this pawn's properties
	APawn_Base();
protected:
	//bool bJump=false;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float value);

	void MoveRight(float value);

	void Turn(float value);

	void LookUp(float value);

	//bool Jumps();

	void Fire();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};
