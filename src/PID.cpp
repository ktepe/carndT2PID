
#include <iostream>
#include "PID.h"

#define ket_debug 1

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

#if ket_debug
	cout << "PID::Init "<< Kp << " "<< Ki << " "<< Kd << endl;
#endif
	PID::Kp=Kp;
	
	PID::Ki=Ki;
	
	PID::Kd=Kd;
	
	cte_t=0.0;
	cte_sum=0.0;

	p_error =0.0;
	i_error = 0.0;
	d_error = 0.0;
	
	first_step=true;
	
}

void PID::UpdateError(double cte) {
	
	if (first_step) {	
		p_error=-Kp*cte;
		i_error=0.0;
		d_error=0.0;
		
		cte_t=cte;
		cte_sum+=cte; 
		
		first_step=false ;
		return;
	}

	p_error=-Kp*cte;
	i_error=-Ki*cte_sum;
  d_error=-Kd*(cte-cte_t);
	cte_t=cte;
		
}

double PID::TotalError() {

	return p_error+i_error+d_error;
	
}

