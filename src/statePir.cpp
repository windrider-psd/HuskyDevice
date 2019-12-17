#include "statePir.h"

void StatePIR::lerSensor()
{
	this->mensagemPIR->payload = digitalRead(GPIO);
}



StatePIR::StatePIR(int gpio):husky::StateSensor(gpio)
{
	this->retornoExecucao.reserve(1);

	this->retornoExecucao.emplace_back("pir", "");

	this->mensagemPIR = &this->retornoExecucao.at(0);

	intervalo = 1;
	pinMode(gpio, INPUT);
}

bool StatePIR::DeveEnviar()
{
	return this->mensagemPIR->payload == "1";
}