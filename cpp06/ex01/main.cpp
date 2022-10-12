/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/04/10 23:09:51 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void printData(Data *data) {
	std::cout << "____________Data____________\n";
	std::cout << "FIRST NAME: " << data->firstName << "\n";
	std::cout << "LAST NAME: " << data->lastName << "\n";
	std::cout << "YEAR BIRTH: " << data->yearBirth << "\n";
	std::cout << "AGE: " << data->age << "\n";
	std::cout << "____________________________\n";
}

int main( ){
	Data data;
	uintptr_t data_serializer;
	Data *data_deserializer;
	
	data.firstName = "Davi";
	data.lastName = "Jesus";
	data.yearBirth = 1992;
	data.age = 29;

	printData(&data);
	std::cout << "address before serialization: " << &data << "\n";
	data_serializer = serialize(&data);
	std::cout << "address after serialization: " << data_serializer << "\n";
	data_deserializer = deserialize(data_serializer);
	std::cout << "deserialized address: " << data_deserializer << "\n";
	printData(data_deserializer);

	return 0;
}