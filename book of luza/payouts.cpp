#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <cmath>

struct Payouts {
	std::vector<std::string> chosen_aspects;//chosen aspects inherited
	std::string payout_text;				// displayed text
	float payout_k;							//koeficijent otplate

};