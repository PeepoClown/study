#include <iostream>
#include <string>
#include <stdint.h>
#include <ctime>
#include <cstdlib>

struct	Data
{
	std::string	s1;
	int			n;
	std::string	s2;
};

void*	serialize(void)
{
	uint8_t	*byteArray = new uint8_t[20];
	int		i = 0;

	std::cout << "first array : ";
	while (i < 8)
	{
		uint8_t	c_tmp = 0;
		while (!std::isalnum(c_tmp))
			c_tmp = rand() % 256;
		byteArray[i++] = c_tmp;
		std::cout << c_tmp;
	}
	std::cout << std::endl;

	int		*num = new int;
	*num = rand() % 2000000 - 1000000;
	std::cout << "num : " << *num << std::endl;
	uint8_t	*numByteArray = reinterpret_cast<uint8_t*>(num);
	while (i < 12)
	{
		byteArray[i] = numByteArray[i - 8];
		i++;
	}

	std::cout << "second array : ";
	while (i < 20)
	{
		uint8_t c_tmp = 0;
		while (!std::isalnum(c_tmp))
			c_tmp = rand() % 256;
		byteArray[i++] = c_tmp;
		std::cout << c_tmp;
	}
	std::cout << std::endl;

	delete num;

	return (byteArray);
}

Data*	deserialize(void *raw)
{
	uint8_t	*byteArray = reinterpret_cast<uint8_t*>(raw);
	int		i = 0;

	uint8_t	*fst_array = new uint8_t[9];
	while (i < 8)
	{
		fst_array[i] = byteArray[i];
		i++;
	}
	fst_array[i] = '\0';

	uint8_t	*num = new uint8_t[4];
	while (i < 12)
	{
		num[i - 8] = byteArray[i];
		i++;
	}

	uint8_t	*scd_array = new uint8_t[9];
	while (i < 20)
	{
		scd_array[i - 12] = byteArray[i];
		i++;
	}
	scd_array[i] = '\0';

	Data *data = new Data;
	data->s1 = reinterpret_cast<char*>(fst_array);
	data->n = *(reinterpret_cast<int*>(num));
	data->s2 = reinterpret_cast<char*>(scd_array);

	delete [] fst_array;
	delete [] num;
	delete [] scd_array;

	return (data);
}

int		main(void)
{
	srand(time(NULL));

	std::cout << "Serializing data" << std::endl;
	void *serializedData = serialize();

	std::cout << "Deserializing data" << std::endl;
	Data *deserializedData = deserialize(serializedData);

	std::cout << "first array : " << deserializedData->s1 << std::endl;
	std::cout << "num : " << deserializedData->n << std::endl;
	std::cout << "second array : " << deserializedData->s2 << std::endl;
	return (0);
}
