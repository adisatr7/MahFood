#include "./components/PageComponent.hpp"
#include "./pages/LoginPage.hpp"


PageComponent loginPage = PageComponent("Login", LoginPage);

int main() {
    loginPage.renderPage();

    return 0;
}