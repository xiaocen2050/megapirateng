#ifndef AP_Baro_BMP085_Pirates_h
#define AP_Baro_BMP085_Pirates_h

#define TEMP_FILTER_SIZE 4
#define PRESS_FILTER_SIZE 8

#include "AP_Baro.h" 

class AP_Baro_BMP085_Pirates: public AP_Baro
{
  public:
	AP_Baro_BMP085_Pirates() {};  // Constructor
  /* AP_Baro public interface: */
  bool init(AP_PeriodicProcess *scheduler);
  uint8_t read();
  int32_t get_pressure();     // in mbar*100 units
  int16_t get_temperature();  // in celsius degrees * 100 units
  float get_altitude();        // in meter units

  int32_t get_raw_pressure();
  int32_t get_raw_temp(); 
  
	static int32_t RawPress;
	static int32_t	_offset_press;
	static int32_t RawTemp;
	int16_t Temp;
	int32_t Press;
	//int Altitude;
	static uint8_t oss;
	//int32_t Press0;  // Pressure at sea level

	private:
	void init_hardware();
	static void _update(uint32_t tnow);

	// Internal calibration registers
	int16_t ac1, ac2, ac3, b1, b2, mb, mc, md;
	uint16_t ac4, ac5, ac6;

	static int	_temp_filter[TEMP_FILTER_SIZE];
	static int	_press_filter[PRESS_FILTER_SIZE];
	static long	_offset_temp;

	static uint8_t	_temp_index;
	static uint8_t	_press_index;

	static void Command_ReadPress();
	static void Command_ReadTemp();
	static void ReadPress();
	static void ReadTemp();
	void Calculate();
};

#endif
