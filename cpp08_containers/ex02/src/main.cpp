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

#include "../inc/MutantStack.hpp"
#include "../inc/Utils.hpp"

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"


/* subject.pdf main()*/
// int main()
// {
//     MutantStack<int> mstack;

//     mstack.push(5);
//     mstack.push(17);

//     std::cout << mstack.top() << std::endl;

//     mstack.pop();

//     std::cout << mstack.size() << std::endl;

//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     mstack.push(0);

//     std::cout << mstack.size() << std::endl;

//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();

//     ++it;
//     --it;

//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }

//     std::stack<int> s(mstack);
    
//     return 0;
// }

/* subject.pdf main() with std::list instead of MutantStack */
// int main()
// {
//     std::list<int> mlist;

//     mlist.push_back(5);
//     mlist.push_back(17);

//     std::cout << mlist.back() << std::endl;  // list has back(), no top()

//     mlist.pop_back();

//     std::cout << mlist.size() << std::endl;

//     mlist.push_back(3);
//     mlist.push_back(5);
//     mlist.push_back(737);
//     mlist.push_back(0);

//     std::cout << mlist.size() << std::endl;

//     std::list<int>::iterator it = mlist.begin();
//     std::list<int>::iterator ite = mlist.end();

//     ++it;
//     --it;

//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }

//     return 0;
// }



/* my main()*/
int rands(void) { return std::rand() % 100; }

struct printWithComma {
    void operator()(int n) const { std::cout << n << ", "; }
};

/* Functor to push elements into MutantStack */
struct pushToStack {
    MutantStack<int>& stack;
    pushToStack(MutantStack<int>& s) : stack(s) {}
    void operator()(int n) { stack.push(n); }
};

int main(void)
{
    const int nToAdd = 5;
    MutantStack<int> mstack;

    std::vector<int> v(nToAdd);
    std::generate(v.begin(), v.end(), rands);

    std::cout << CYAN << "Adding " << nToAdd << " numbers to MutantStack..." << RESET << std::endl;
    std::for_each(v.begin(), v.end(), pushToStack(mstack));
    std::cout << GREEN << "Numbers added!\n" << RESET << std::endl;

    std::cout << YELLOW << "MutantStack contents: [" << RESET;
    std::for_each(mstack.begin(), mstack.end(), printWithComma());
    std::cout << YELLOW << "]\n" << RESET << std::endl << std::endl;

    std::cout << BLUE << "Pushing 42..." << RESET << std::endl;
    mstack.push(42);

    std::cout << YELLOW << "MutantStack contents: [" << RESET;
    std::for_each(mstack.begin(), mstack.end(), printWithComma());
    std::cout << YELLOW << "]\n" << RESET;

    std::cout << "Top element: " << mstack.top() << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl << std::endl;

    std::cout << BLUE << "Popping top element..." << RESET << std::endl;
    mstack.pop();

    std::cout << YELLOW << "MutantStack contents: [" << RESET;
    std::for_each(mstack.begin(), mstack.end(), printWithComma());
    std::cout << YELLOW << "]\n" << RESET;

    std::cout << "New top: " << mstack.top() << std::endl;
    std::cout << "Size after pop: " << mstack.size() << std::endl << std::endl;

    std::cout << PURPLE << "Testing iterators (++it, --it):" << RESET << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    std::cout << "First element after ++ : " << *it << std::endl;
    --it;
    std::cout << "First element after -- : " << *it << std::endl;

    std::cout << YELLOW << "Iterating full MutantStack: [" << RESET;
    while (it != ite) {
        std::cout << *it << ", ";
        ++it;
    }
    std::cout << YELLOW << "]\n" << RESET << std::endl;

    std::cout << CYAN << "Testing Copy Constructor..." << RESET << std::endl;
    MutantStack<int> copyStack(mstack);
    std::cout << "Copy contents: [";
    std::for_each(copyStack.begin(), copyStack.end(), printWithComma());
    std::cout << "]" << std::endl;
    std::cout << PURPLE << "Original stack address: " << &mstack << RESET << std::endl;
    std::cout << PURPLE << "Copy stack address:     " << &copyStack << RESET << std::endl << std::endl;

    std::cout << CYAN << "Testing Assignment Operator..." << RESET << std::endl;
    MutantStack<int> assignStack;
    assignStack = mstack;
    std::cout << "Assigned contents: [";
    std::for_each(assignStack.begin(), assignStack.end(), printWithComma());
    std::cout << "]" << std::endl;
    std::cout << PURPLE << "Original stack address:  " << &mstack << RESET << std::endl;
    std::cout << PURPLE << "Assigned stack address:  " << &assignStack << RESET << std::endl << std::endl;

    return 0;
}