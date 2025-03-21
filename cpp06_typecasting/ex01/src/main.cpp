/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:30:54 by rocky             #+#    #+#             */
/*   Updated: 2024/08/26 17:31:01 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.hpp"
#include "../inc/Serialiser.hpp"

/*
  - shows how to safely convert pointers to raw integers and back
  - mimicking how data is serialised (flattened) for storage / transfer
  ------------------------------------------------------------------------------
  - say two systems/processes share memory, so both have Data obj instance
  - we can't store/transfer the pointer, it's valid only in current process
  - so we convert to uintptr_t
  - this simple number can be written, stored & transmitted between processes
*/
int main(void)
{
    Data data1;
    data1.id = 69;
    data1.name = "Zach";

    Data data2;
    data2.id = 420;
    data2.name = "Cody";

    uintptr_t raw1 = Serialiser::serialise(&data1);
    uintptr_t raw2 = Serialiser::serialise(&data2);

    Data* ptr1 = Serialiser::deserialise(raw1);
    Data* ptr2 = Serialiser::deserialise(raw2);

    std::ostringstream oss;
    oss << "Original data1 address: " << &data1;
    printStr(oss.str(), "C");

    oss.str(""); oss.clear();
    oss << "Deserialised ptr1 address: " << ptr1;
    printStr(oss.str(), "C");

    oss.str(""); oss.clear();
    oss << "Original data2 address: " << &data2;
    printStr(oss.str(), "Y");

    oss.str(""); oss.clear();
    oss << "Deserialised ptr2 address: " << ptr2;
    printStr(oss.str(), "Y");

    printStr("Data1 name: " + ptr1->name + ", id: " + 
        static_cast<std::ostringstream&>(oss.seekp(0) << ptr1->id).str(), "P");
    printStr("Data2 name: " + ptr2->name + ", id: " + 
        static_cast<std::ostringstream&>(oss.seekp(0) << ptr2->id).str(), "P");

    if (ptr1 == &data1 && ptr2 == &data2)
        printStr("Success: Deserialised pointers match original addresses", "G");
    else
        printStr("Failure: Deserialised pointers do not match", "R");

    return 0;
}