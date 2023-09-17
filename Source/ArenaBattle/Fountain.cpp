// Fill out your copyright notice in the Description page of Project Settings.


#include "Fountain.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PointLightComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AFountain::AFountain()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	RootComponent = body;
	ConstructorHelpers::FObjectFinder<UStaticMesh> temp_Body(TEXT("/Script/Engine.StaticMesh'/Game/InfinityBladeGrassLands/Environments/Plains/Env_Plains_Ruins/StaticMesh/SM_Plains_Castle_Fountain_01.SM_Plains_Castle_Fountain_01'"));
	if (temp_Body.Succeeded())
	{
		body->SetStaticMesh(temp_Body.Object);
	}

	water = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Water"));
	water->SetupAttachment(body);
	water->SetRelativeLocation(FVector(0, 0, 0));
	ConstructorHelpers::FObjectFinder<UStaticMesh> temp_Water(TEXT("/Script/Engine.StaticMesh'/Game/InfinityBladeGrassLands/Environments/Plains/Env_Plains_Ruins/StaticMesh/SM_Plains_Castle_Fountain_02.SM_Plains_Castle_Fountain_02'"));
	if (temp_Water.Succeeded())
	{
		water->SetStaticMesh(temp_Water.Object);
	}

	light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));
	light->SetupAttachment(body);
	light->SetRelativeLocation(FVector(0, 0, 195));

	splash = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Splash"));
	splash -> SetupAttachment(RootComponent);
	splash -> SetRelativeLocation(FVector(0,0,195));
	ConstructorHelpers::FObjectFinder<UParticleSystem> temp_Splash(TEXT("/Script/Engine.ParticleSystem'/Game/InfinityBladeGrassLands/Effects/FX_Ambient/Water/P_Water_Fountain_Splash_Base_01.P_Water_Fountain_Splash_Base_01'"));
	if (temp_Splash.Succeeded())
	{
		splash->SetTemplate(temp_Splash.Object);
	}
}

// Called when the game starts or when spawned
void AFountain::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AFountain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

