/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_header.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/11 19:26:09 by vtenneke      #+#    #+#                 */
/*   Updated: 2021/02/11 19:26:09 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HEADER_HPP
# define TEST_HEADER_HPP

# include <iostream>

#define WHITE "\033[37;01m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[m"

#define VALUE int

#ifdef STD_TEST 
	using namespace std;
	#define ENV "STD"
	#define SIDE RED
	#define ENVART "  █████████  ███████████ ██████████  \n\
 ███░░░░░███░█░░░███░░░█░░███░░░░███ \n\
░███    ░░░ ░   ░███  ░  ░███   ░░███\n\
░░█████████     ░███     ░███    ░███\n\
 ░░░░░░░░███    ░███     ░███    ░███\n\
 ███    ░███    ░███     ░███    ███ \n\
░░█████████     █████    ██████████  \n\
 ░░░░░░░░░     ░░░░░    ░░░░░░░░░░   \n"
#else
	using namespace ft;
	#define ENV "FT"
	#define SIDE BLUE
	#define ENVART " ███████████ ███████████\n\
░░███░░░░░░█░█░░░███░░░█\n\
 ░███   █ ░ ░   ░███  ░ \n\
 ░███████       ░███    \n\
 ░███░░░█       ░███    \n\
 ░███  ░        ░███    \n\
 █████          █████   \n\
░░░░░          ░░░░░    \n"        
#endif

#define WARS " █████   ███   █████   █████████   ███████████    █████████ \n\
░░███   ░███  ░░███   ███░░░░░███ ░░███░░░░░███  ███░░░░░███\n\
 ░███   ░███   ░███  ░███    ░███  ░███    ░███ ░███    ░░░ \n\
 ░███   ░███   ░███  ░███████████  ░██████████  ░░█████████ \n\
 ░░███  █████  ███   ░███░░░░░███  ░███░░░░░███  ░░░░░░░░███\n\
  ░░░█████░█████░    ░███    ░███  ░███    ░███  ███    ░███\n\
    ░░███ ░░███      █████   █████ █████   █████░░█████████ \n\
     ░░░   ░░░      ░░░░░   ░░░░░ ░░░░░   ░░░░░  ░░░░░░░░░  \n"

void print_env() {
	std::cout << std::endl << SIDE << ENVART << std::endl;
	std::cout << std::endl << WARS << RESET << std::endl;
}

void print_title_saber(std::string name) {
	int add = 0;
	if (name.size() % 2)
		add++;
	int size = (50 - name.size()) / 2;
	std::cout << "   ▁▁▁▁▁▁▁▁▁▁▁▁▁" << SIDE << " ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁" << RESET << std::endl;
	std::cout << "|▍░▐░░▣░▒░▒░▒▕|" << std::string(size, ' ') << WHITE << name << SIDE << std::string(size + add, ' ') << "  ▌" << RESET << std::endl;
	std::cout << "   ▔▔▔▔▔▔▔▔▔▝▔▔▔" << SIDE << " ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔" << RESET << std::endl;
}

void print_container_title_tiefighter(std::string name) {
	int size = (6 - name.size()) / 2;
	std::cout << WHITE << "              _              _\n";
	std::cout << "             //              \\\n";
	std::cout << "            /'                `\\\n";
	std::cout << "           /,'     ..--..     `.\\\n";
	std::cout << "          /,'   .''      ``.   `.\\\n";
	std::cout << "         /,'   :   .----.   :   `.\\\n";
	std::cout << "        I I   :  .'\\    /`.  :   I I\n";
	std::cout << "        I b__:   . " << std::string(size, ' ') << SIDE << name << WHITE << std::string(size, ' ') << " .   :__d I\n";
	std::cout << "        I p~~:   . `.__.' .   :~~q I\n";
	std::cout << "        I I   :   ./    \\.   :   I I\n";
	std::cout << "         \\`.   :   `----'   :   ,'/\n";
	std::cout << "          \\`.   `..      ..'   ,'/\n";
	std::cout << "           \\`.     ``~~''     ,'/\n";
	std::cout << "            \\`                '/\n";
	std::cout << "             \\               //\n";
	std::cout << "              ~              ~\n" << RESET << std::endl;

}

void print_container_title_xwing(std::string name) {
	int size = (18 - name.size()) / 2;
	std::cout << WHITE << "                                               ____________\n";
	std::cout << "                                --)-----------|____________|\n";
	std::cout << "                                              ,'       ,'\n";
	std::cout << "                -)------========            ,'  ____ ,'\n";
	std::cout << "                         `.    `.         ,'  ,'__ ,'\n";
	std::cout << "                           `.    `.     ,'       ,'\n";
	std::cout << "                             `.    `._,'_______,'__\n";
	std::cout << "                               [._ _| ^--      || |\n";
	std::cout << "                       ____,...-----|__________ll_|\\\n";
	std::cout << "      ,.,..-------\"\"\"\"\"     \"----'" << std::string(size, ' ') << SIDE << name << WHITE << std::string(size, ' ') << "|\n";
	std::cout << "  .-\"\"  |=========================== ______________ |\n";
	std::cout << "   \"-...l_______________________    |  |'      || |_]\n";
	std::cout << "                                [`-.|__________ll_|\n";
	std::cout << "                              ,'    ,' `.        `.\n";
	std::cout << "                            ,'    ,'     `.    ____`.\n";
	std::cout << "                -)---------========        `.  `.____`.\n";
	std::cout << "                                             `.        `.\n";
	std::cout << "                                               `.________`.\n";
	std::cout << "                               --)-------------|___________|\n" << RESET << std::endl;
}


template <class Container>
void print_container(Container& cont, std::string name) {
	std::cout << name << " ";
	std::cout << "[";
	for (typename Container::iterator it = cont.begin(); it != cont.end();)
		std::cout << SIDE << *it << RESET << (++it != cont.end() ? ", " : "");
	std::cout << "]" << std::endl << std::endl;
}

template <class Container>
void print_container_reverse(Container& cont, std::string name) {
	std::cout << name << " ";
	std::cout << "[";
	for (typename Container::reverse_iterator it = cont.rbegin(); it != cont.rend();)
		std::cout << SIDE << *it << RESET << (++it != cont.rend() ? ", " : "");
	std::cout << "]" << std::endl << std::endl;
}

void print_container_title(std::string name) {
	#ifdef STD_TEST
		print_container_title_tiefighter(name);
	#else
		print_container_title_xwing(name);
	#endif
}

void print_title(std::string name) {
	int size = (50 - name.size()) / 4;
	std::cout << std::string(50, '-') << std::endl;
	std::cout << std::string(size * 2, ' ') << WHITE << name << RESET << std::string(size * 2, ' ') << std::endl; 
	std::cout << std::string(50, '-') << std::endl;
}

template <typename Container>
void	comparison_operator_container(Container a, Container b, std::string a_title, std::string b_title)
{
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << a_title << YELLOW << " operator == " << RESET << b_title << " = " << ((a == b) ? GREEN "True" : RED "False") << RESET << std::endl;
	std::cout << a_title << YELLOW << " operator != " << RESET << b_title << " = " << ((a != b) ? GREEN "True" : RED "False") << RESET << std::endl;
	std::cout << a_title << YELLOW << " operator <  " << RESET << b_title << " = " << ((a < b) ? GREEN "True" : RED "False") << RESET << std::endl;
	std::cout << a_title << YELLOW << " operator <= " << RESET << b_title << " = " << ((a <= b) ? GREEN "True" : RED "False") << RESET << std::endl;
	std::cout << a_title << YELLOW << " operator >  " << RESET << b_title << " = " << ((a > b) ? GREEN "True" : RED "False") << RESET << std::endl;
	std::cout << a_title << YELLOW << " operator >= " << RESET << b_title << " = " << ((a >= b) ? GREEN "True" : RED "False") << RESET << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << b_title << YELLOW << " operator == " << RESET << a_title << " = " << ((b == a) ? GREEN "True" : RED "False") << RESET << std::endl;
	std::cout << b_title << YELLOW << " operator != " << RESET << a_title << " = " << ((b != a) ? GREEN "True" : RED "False") << RESET << std::endl;
	std::cout << b_title << YELLOW << " operator <  " << RESET << a_title << " = " << ((b < a) ? GREEN "True" : RED "False") << RESET << std::endl;
	std::cout << b_title << YELLOW << " operator <= " << RESET << a_title << " = " << ((b <= a) ? GREEN "True" : RED "False") << RESET << std::endl;
	std::cout << b_title << YELLOW << " operator >  " << RESET << a_title << " = " << ((b > a) ? GREEN "True" : RED "False") << RESET << std::endl;
	std::cout << b_title << YELLOW << " operator >= " << RESET << a_title << " = " << ((b >= a) ? GREEN "True" : RED "False") << RESET << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
}


#endif
