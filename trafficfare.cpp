#include <iostream>
#include <vector>

//this condition evalutes whether or not we should buy a 7day pass with our remaining days
void whichPassToPurchase(int day, int how_many_riding, std::vector<double> ticket_prices) {
  int remaining_days = day % 7;
  double remaining_days_ride_total = remaining_days * how_many_riding * ticket_prices[0];
  int _7_day_tickets = day / 7;
  double _7_day_ticket_total = _7_day_tickets * ticket_prices[1];
  int remaining_days_riding = remaining_days * how_many_riding;
  double per_ride_total = day * how_many_riding * ticket_prices[0];
  double saving_money1 = per_ride_total - ticket_prices[2] ;
  double saving_money2 = per_ride_total - ticket_prices[1] ;

  if (7 < day && day <= 30) {
    if(_7_day_ticket_total + remaining_days_ride_total < ticket_prices[2]){
    	std::cout << "You should buy " <<	_7_day_tickets << " 7-day tickets and " << remaining_days_riding <<" per ride ticket(s)\n";
      std::cout << "You saved " << saving_money1 << " dollars! \n" ;
    } else {
      std::cout << "You should buy " <<	1 << " 30-day ticket\n";
    }
  } else if ( day <= 7 ) {
    	if(per_ride_total > ticket_prices[1] && ticket_prices[2] > per_ride_total ){
    	  std::cout << "You should buy " << _7_day_tickets << " 7-day tickets\n";
        std::cout << "You saved " << saving_money2 << " dollars! \n" ;
    	} else if (per_ride_total >= ticket_prices[2]){
    	   std::cout << "You should buy 30-day ticket \n";
         std::cout << "You saved " << saving_money1 << " dollars! \n" ;
    	} else {
    	    std::cout <<"You should buy per ride ticket \n";
    	}
  }
}

//harded fares for subway system and determine the cheapest combination fares
//how many days is this person riding and how frequently they will be riding
int main(){

	std::vector<double> ticket_prices = {2.75, 32.0, 121.0};
  std::vector<std::string> ticket_price_id = {"per ride", "7 day", "30 day"};
  
  int day = 0; 
  int how_many_riding;

  while (day > 30  ||  day < 1) {
    std::cout<< "How many days are you riding in a month enter a number 1 - 30:\n" ;
    std::cin >> day ;

  	if ( 30 >= day  && day >= 1 ) {
    	break;
  	}
    std::cout << "It's a invalid number" ;
  }

  std::cout<< "How many times per day will you be riding: \n" ;
  std::cin >> how_many_riding ;
  
  whichPassToPurchase(day, how_many_riding, ticket_prices);

}
