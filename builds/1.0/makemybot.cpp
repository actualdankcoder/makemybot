#include <iostream> 
#include <fstream>
#include <string>
#include <sstream>
using namespace std; 
bool check_number(string str) {
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false)
      return false;
      return true;
} 
int main(int argc, char** argv) 
{ 
   if (argc==2){
       if (std::string(argv[1]) == "python" || std::string(argv[1]) == "ruby") {
           if (std::string(argv[1]) == "python") {
               string prefix;
               string commandname;
               string commandreply;
               string embedtitle;
               string embed_description;
               string embedimg;
               string embedfieldname;
               string embedfieldvalue;
               string token;
               int commandtype;
               int addimage;
               ofstream bot;
               bot.open("botcode.py");
               cout << "[*] CREATED FILE botcode.py\n";
               bot << "import discord\n";
               bot << "from discord.ext import commands\n";
               cout << "[*] IMPORTED DISCORD AND ITS SUBMODULES\n";
               cout <<  "[*] What should be the prefix of your bot: ";
               cin >> prefix;
               bot << "client=commands.Bot(command_prefix='!')\n";
               cout << "[*] SUCESSFULLY SET PREFIX TO " << prefix << "\n";
               cout << "[*] We will now be adding commands, enter 0 whenever you feel like you're done adding commands: \n\n\n";
               while (true) {
                   cout << "[*] Select a type of command, you would like to add || Enter 0 to exit\n";
                   cout << "    [1] Normal Message\n";
                   cout << "    [2] Embed Message\n";
                   cout << "    [3] Ban Command(no config required)\n";
                   cout << "    [3] Kick Command(no config required)\n";
                   cout << "[*] Enter a number [1-4]: ";
                   cin >> commandtype;
                   switch(commandtype) {
                       case 0:
                            break;
                       case 1:
                            bot << "@client.command()\n";
                            cout << "[*] Please enter a command name: ";
                            cin >> commandname;     
                            bot << "async def " << commandname << "(ctx):" << "\n";
                            cout << "[*] What should be the bot's reply for this command: ";
                            getline(cin >> ws, commandreply);
                            bot << "    await ctx.send('" + commandreply + "')\n";
                            cout << "[*] Command was successfully created\n";
                            break;
                       case 2:
                            bot << "@client.command()\n";
                            cout << "[*] Please enter a command name: ";
                            cin >> commandname;     
                            bot << "async def " << commandname << "(ctx):" << "\n";
                            bot << "    embed=discord.Embed()\n";
                            cout << "[*] Please set the title of the embed: ";
                            getline(cin >> ws, embedtitle);
                            bot << "    embed.title='" << embedtitle << "'\n";
                            cout << "[*] Please set the description of the embed: ";
                            getline(cin >> ws, embed_description);
                            bot << "    embed.description='" << embed_description << "'\n";
                            cout << "[*] (Optional) Add an image to the embed, enter 1 to add an image or leave empty if you do not want to: ";
                            cin >> addimage;
                            if (addimage==1){
                                cout << "[*] Please enter a *VALID* image url: ";
                                cin >> embedimg;
                                bot << "    embed.set_image(url='" << embedimg << "')\n";
                                cout << "[*] Image has been added to the embed\n";
                            }
                            bot << "    await ctx.send(embed=embed)\n";
                            cout << "[*] Embed has been successfully added\n";
                            break;   
                       case 3:
                            bot << "@client.command()\n";
                            bot << "async def ban(ctx, member: discord.Member=None):\n";
                            bot << "    if not member:\n";
                            bot << "        await ctx.send('Please mention a member')\n";
                            bot << "        return\n";
                            bot << "    await member.ban()\n";
                            bot << "    await ctx.send(f'{member.display_name} was banned from the server')\n";
                            cout << "[*] Ban Command was added\n";
                            break;
                       case 4:
                            bot << "@client.command()\n";
                            bot << "async def kick(ctx, member: discord.Member=None):\n";
                            bot << "    if not member:\n";
                            bot << "        await ctx.send('Please mention a member')\n";
                            bot << "        return\n";
                            bot << "    await member.kick()\n";
                            bot << "    await ctx.send(f'{member.display_name} was kicked from the server')\n";
                            cout << "[*] Kick Command was added\n";
                            break;
                       default:
                            break;                          
                   }
                   if (commandtype==0) {
                       break;
                   }

               }
               cout << "[*] Now copy paste your token: ";
               cin >> token;
               bot << "client.run('" << token << "')";
               bot.close();
               cout << "[*] TOKEN HAS BEEN ADDED\n";
               cout << "[*] Bot has been created, you can test it using: python botcode.py\n";
           }
       }
   }
   else {
       cout << "please specify the language you want to work in\n";
   }
    return 0; 
} 
