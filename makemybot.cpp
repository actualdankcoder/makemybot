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
               string randomreply;
               int commandtype;
               int addimage;
               ofstream bot;
               bot.open("botcode.py");
               cout << "[*] CREATED FILE botcode.py\n";
               bot << "import discord, random\n";
               bot << "from discord.ext import commands\n";
               cout << "[*] IMPORTED RANDOM,DISCORD AND ITS SUBMODULES\n";
               cout <<  "[*] What should be the prefix of your bot: ";
               cin >> prefix;
               bot << "client=commands.Bot(command_prefix='!')\n";
               cout << "[*] SUCESSFULLY SET PREFIX TO " << prefix << "\n";
               cout << "[*] We will now be adding commands, enter 0 whenever you feel like you're done adding commands: \n\n\n";
               while (true) {
                   cout << "[*] Select a type of command, you would like to add || Enter 0 to exit\n";
                   cout << "    [1] Normal Message\n";
                   cout << "    [2] Direct Message\n";
                   cout << "    [3] Embed Message\n";
                   cout << "    [4] Ban Command(no config required)\n";
                   cout << "    [5] Kick Command(no config required)\n";
                   cout << "    [6] Randomized Message\n";
                   cout << "    [7] Randomized Direct Message\n";
                   cout << "    [8] Randomized Embed Message\n";
                   cout << "    [9] Randomized Direct Embed Message\n";
                   cout << "    [10] Broadcast Message(no config required)\n";
                   cout << "    [11] Embed Broadcast Message(no config required)\n";                   
                   cout << "[*] Enter a number [1-8]: ";
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
                            cout << "[*] What should be the bot's reply for this command: ";
                            getline(cin >> ws, commandreply);
                            bot << "    await ctx.author.send('" + commandreply + "')\n";
                            cout << "[*] Command was successfully created\n";
                            break;
                       case 3:
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
                            cout << "[*] (Optional) Add an image to the embed, enter 1 to add an image or enter 0 if you do not want to: ";
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
                       case 4:
                            bot << "@client.command()\n";
                            bot << "@commands.has_permissions(ban_members=True)\n";
                            bot << "async def ban(ctx, member: discord.Member=None):\n";
                            bot << "    if not member:\n";
                            bot << "        await ctx.send('Please mention a member')\n";
                            bot << "        return\n";
                            bot << "    await member.ban()\n";
                            bot << "    await ctx.send(f'{member.display_name} was banned from the server')\n";
                            cout << "[*] Ban Command was added || " << prefix << "ban\n";
                            break;
                       case 5:
                            bot << "@client.command()\n";
                            bot << "@commands.has_permissions(kick_members=True)\n";
                            bot << "async def kick(ctx, member: discord.Member=None):\n";
                            bot << "    if not member:\n";
                            bot << "        await ctx.send('Please mention a member')\n";
                            bot << "        return\n";
                            bot << "    await member.kick()\n";
                            bot << "    await ctx.send(f'{member.display_name} was kicked from the server')\n";
                            cout << "[*] Kick Command was added || " << prefix << "kick\n";
                            break;
                       case 6:
                            bot << "@client.command()\n";
                            cout << "[*] Please enter a command name: ";
                            cin >> commandname;     
                            bot << "async def " << commandname << "(ctx):" << "\n";
                            cout << "[*] You will be prompted with a reply adding system, enter as many random replies as you want\n";
                            cout << "[*] Once you are done adding random replies, just type EXITSESSION\n\n";
                            bot << "    replies=[";
                            while(true){
                                cout << "[*] Add Random reply: ";
                                getline(cin >> ws, randomreply);
                                if(randomreply=="EXITSESSION"){
                                    break;
                                }
                                bot << "'" << randomreply << "',";
                                cout << "[*] Reply Added: " << randomreply << "\n";
                            }
                            bot << "]\n";
                            bot << "    await ctx.send(random.choice(replies))\n";
                            break;
                       case 7:
                            bot << "@client.command()\n";
                            cout << "[*] Please enter a command name: ";
                            cin >> commandname;     
                            bot << "async def " << commandname << "(ctx):" << "\n";
                            cout << "[*] You will be prompted with a reply adding system, enter as many random replies as you want\n";
                            cout << "[*] Once you are done adding random replies, just type EXITSESSION\n\n";
                            bot << "    replies=[";
                            while(true){
                                cout << "[*] Add Random reply: ";
                                getline(cin >> ws, randomreply);
                                if(randomreply=="EXITSESSION"){
                                    break;
                                }
                                bot << "'" << randomreply << "',";
                                cout << "[*] Reply Added: " << randomreply << "\n";
                            }
                            bot << "]\n";
                            bot << "    await ctx.author.send(random.choice(replies))\n";
                            break;   
                       case 8:
                            bot << "@client.command()\n";
                            cout << "[*] Please enter a command name: ";
                            cin >> commandname;     
                            bot << "async def " << commandname << "(ctx):" << "\n";
                            bot << "    embed=discord.Embed()\n";
                            cout << "[*] Please set the title of the embed: ";
                            getline(cin >> ws, embedtitle);
                            bot << "    embed.title='" << embedtitle << "'\n";                           
                            cout << "[*] You will be prompted with a reply adding system, enter as many random replies as you want\n";
                            cout << "[*] Once you are done adding random replies, just type EXITSESSION\n\n";
                            bot << "    replies=[";
                            while(true){
                                cout << "[*] Add Random reply: ";
                                getline(cin >> ws, randomreply);
                                if(randomreply=="EXITSESSION"){
                                    break;
                                }
                                bot << "'" << randomreply << "',";
                                cout << "[*] Reply Added: " << randomreply << "\n";
                            }
                            bot << "]\n";
                            bot << "    embed.description=random.choice(replies)\n";
                            bot << "    await ctx.send(embed=embed)\n";
                            break;  
                       case 9:
                            bot << "@client.command()\n";
                            cout << "[*] Please enter a command name: ";
                            cin >> commandname;     
                            bot << "async def " << commandname << "(ctx):" << "\n";
                            bot << "    embed=discord.Embed()\n";
                            cout << "[*] Please set the title of the embed: ";
                            getline(cin >> ws, embedtitle);
                            bot << "    embed.title='" << embedtitle << "'\n";                           
                            cout << "[*] You will be prompted with a reply adding system, enter as many random replies as you want\n";
                            cout << "[*] Once you are done adding random replies, just type EXITSESSION\n\n";
                            bot << "    replies=[";
                            while(true){
                                cout << "[*] Add Random reply: ";
                                getline(cin >> ws, randomreply);
                                if(randomreply=="EXITSESSION"){
                                    break;
                                }
                                bot << "'" << randomreply << "',";
                                cout << "[*] Reply Added: " << randomreply << "\n";
                            }
                            bot << "]\n";
                            bot << "    embed.description=random.choice(replies)\n";
                            bot << "    await ctx.author.send(embed=embed)\n";
                            break;  
                       case 10:
                            bot << "@client.command(aliases=['bc'])\n";
                            bot << "async def broadcast(ctx, *, msg):\n";
                            bot << "    await ctx.send(msg)\n";
                            bot << "    await ctx.message.delete()\n";
                            cout << "[*] Broadcast command was automatically added || " << prefix << "bc, " << prefix << "broadcast\n";
                            break;  
                       case 11:
                            bot << "@client.command(aliases=['rbc'])\n";
                            bot << "async def richbroadcast(ctx, *, msg):\n";
                            bot << "    embed=discord.Embed()\n";
                            bot << "    embed.title='Broadcast Message'\n";
                            bot << "    embed.description=msg\n";                         
                            bot << "    await ctx.send(embed=embed)\n";
                            bot << "    await ctx.message.delete()\n";
                            cout << "[*] Rich Broadcast command was automatically added || " << prefix << "rbc, " << prefix << "richbroadcast\n";
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
