#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class Application {
    public:
                                Application();
        void                    run();

    private:
        void			    	processInput();
		void			    	update(sf::Time dt);
		void			    	render();

    private:
        static const sf::Time	TimePerFrame;

        sf::RenderWindow        mWindow;

};

#endif // APPLICATION_HPP