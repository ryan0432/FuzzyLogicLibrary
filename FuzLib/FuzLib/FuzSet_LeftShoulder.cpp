#include "FuzSet_LeftShoulder.h"

float FuzSet_LeftShoulder::CalculateDOM(float val) const
{
	//If input value equals peak value
	if (val <= m_dPeak && val >= m_dLeft)
	{
		//DOM will always be 1
		return 1.0f;
	}
	//If input value falls on the ramp
	else if (val > m_dPeak && val < m_dRight)
	{
		//DOM will be same ration to PeakDOM / PeakCrisp
		float DOM = (m_dRight - val) / (m_dRight - m_dPeak);
		return DOM;
	}
	else //If input value is larger than right or smaller than right
	{
		//DOM will always be 0
		return 0.0f;
	}
}
