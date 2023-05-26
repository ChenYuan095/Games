// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCore/Pawn_Base.h"
#include"Components/SkeletalMeshComponent.h"
#include"Camera/CameraComponent.h"
#include"Components/CapsuleComponent.h"
#include"GameFramework/SpringArmComponent.h"
// Sets default values
APawn_Base::APawn_Base()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetCapsuleHalfHeight(88.0f);
	Capsule->SetCapsuleRadius(44.0f);
	PlayerMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PlayerMesh"));
	PlayerMesh->SetupAttachment(Capsule);
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bDoCollisionTest = false;
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	SpringArm->SetupAttachment(Capsule);
	
	Gun=CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun"));
	


}

// Called when the game starts or when spawned
void APawn_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APawn_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APawn_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APawn_Base::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APawn_Base::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn_Base::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn_Base::LookUp);
	//PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APawn_Base::Jump);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APawn_Base::Fire);

}




void APawn_Base::MoveForward(float value) 
{

	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0;
	ControlRot.Roll = 0;

	if (value!=0)
	{
		AddMovementInput(ControlRot.Vector(), value);

	}
}

void APawn_Base::MoveRight(float value) 
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0;
	ControlRot.Roll = 0;
	FVector RightVector = FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);
	if (value!=0)
	{
		AddMovementInput(RightVector, value);

	}
}

//bool APawn_Base::Jumps() 
//{
//		return !bJump;
//}

void APawn_Base::Fire() 
{

}

void APawn_Base::Turn(float value)
{
	AddControllerYawInput(value);
}

void APawn_Base::LookUp(float value) 
{

	AddControllerPitchInput(value);

}

