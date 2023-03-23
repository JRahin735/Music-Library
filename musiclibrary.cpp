/// Assignment details and provided code are created and
/// owned by Adam T Koehler, PhD - Copyright 2023.
/// University of Illinois Chicago - CS 251 Spring 2023
#include <iomanip>
#include <iostream>
#include <string>
#include "helpers.cpp"
#include <map>
#include <algorithm>
#include <set>
using namespace std;

void searchSong (map<string, set<string>>&Albums, set<string>& resultSet, string searchWord){

    for (auto i = Albums.begin(); i != Albums.end(); i++){
        for (auto a : i->second){
            // if song found on an album, then store it in result set
            if (searchWord == a){
                resultSet.emplace(i->first);
            }
        }
    }
}

void searchArtist (map<string, set<string>>&Artists, set<string>& resultSet, string searchWord){

    for (auto i = Artists.begin(); i != Artists.end(); i++){
        if (searchWord == i->first){
            for (auto a : i->second){
                resultSet.emplace(a);
            }
        }
    }
}

void searchAlbum (set <string>& AlbumDB, set <string>& resultSet, string searchWord){

    for (auto i : AlbumDB){
        if (i == searchWord){
            resultSet.emplace(i);
        }
    }
}

void load (map<string, set<string>>& Albums, map<string, set<string>>& Artists,
           set<string>& ArtistsDB, set<string>& AlbumsDB, set<string>&SongsDB,
           string remains){

    string Line;
    int count = 0;
    string AlbumName = "";
    ifstream fileSTR (remains);
    if (fileSTR.is_open()){
        while (!fileSTR.eof()){
            getline(fileSTR, Line);
            // Saves Album Names
            if(AlbumName == "" || AlbumName == Line){
                AlbumName = Line;
                count++;
            }
            if (Line != AlbumName){
                // Saves Artist Names
                if (Line[0] != '0' && Line[0] != '1'){
                    string ArtistName = Line;
                    Artists[ArtistName].emplace(AlbumName);
                    ArtistsDB.insert(ArtistName);
                }
                // Saves Song Names
                else if (Line[0] == '0' || Line[0] == '1'){
                    string SongName = Line;
                    Albums[AlbumName].emplace(SongName);
                    SongsDB.insert(SongName);
                }
            }
            else {
                if (count == 2) {
                    if (AlbumName != "") {
                        AlbumsDB.insert(AlbumName);
                    }
                    AlbumName = "";
                    count = 0;
                }
            }
        }
    } else {
        if (remains != "") {
            cout << "Error: Could not open music library file - " << remains << endl;
        }
    }
}

void stats (map<string, set<string>>& Albums, map<string, set<string>>& Artists,
            set<string>& ArtistsDB, set<string>& AlbumsDB, set<string>&SongsDB,
            string remains){

    int totalAlbums = AlbumsDB.size();
    int totalArtists = ArtistsDB.size();
    int totalSongs = SongsDB.size();

    cout << "Overall Music Library Stats" << endl;
    cout << "===========================" << endl;
    cout << "Total Records: " << totalAlbums << endl;
    cout << "Total Unique Artists: " << totalArtists << endl;
    cout << "Total Songs: " << totalSongs << endl << endl;

    if (remains == "-d"){

        cout <<"Your Current Music Library Includes" << endl;
        cout << "===================================" << endl;

        // Finding all Album names
        for (auto i = Albums.begin(); i != Albums.end(); i++) {
            // Printing Album Name
            cout << i->first << endl;
            // Finding all Atrist names that worked on a particular album
            for (auto j = Artists.begin(); j != Artists.end(); j++){
                for(auto a : j-> second) {
                    if (a == i->first) {
                        // Printing all artist names
                        cout << " " << j->first << endl;
                    }
                }
            }
            // Finding all song names inside 1 album
            for (auto b : i->second) {
                // printing song name
                cout << "   " << b << endl;
            }
        }
        cout << endl;
    }
}

void expo (map<string, set<string>>& Albums, map<string, set<string>>& Artists, string remains){

    if (remains == "") {
        remains = "musicdatabase.txt";
    }
    ofstream out (remains);
        // Finding all Album names
        for (auto i = Albums.begin(); i != Albums.end(); i++) {
            // Printing Album Name
            out << i->first << endl;
            // Finding all Atrist names that worked on a particular album
            for (auto j = Artists.begin(); j != Artists.end(); j++) {
                for (auto a: j->second) {
                    if (a == i->first) {
                        // Printing all artist names
                        out << j->first << endl;
                    }
                }
            }
            // Finding all song names inside 1 album
            for (auto b: i->second) {
                // printing song name
                out << b << endl;
            }
            // Printing Album Name
            out << i->first << endl;
        }

    out.close();
}

void search (map<string, set<string>>& Albums, map<string, set<string>>& Artists,
             set<string>& ArtistsDB, set<string>& AlbumsDB, set<string>&SongsDB,
             string remains){

    string secondaryCMD = "";
    string searchPhrase = "";
    splitFirstWord(remains, secondaryCMD, searchPhrase);

    if (secondaryCMD == "song"){

    }
    else if (secondaryCMD == "artist"){

    }
    else if (secondaryCMD == "album"){

    }
    else {
        cout << "Error: Search terms cannot be empty." << endl << "No results found." << endl;
    }
}

int main()
{
    string userEntry;
    string command, remains;

    set <string> SongsInAnAlbum;
    set <string> AlbumsOfAnArtist;
    map <string, set<string>> Albums;
    map <string, set<string>> Artists;

    set <string> ArtistsDB;
    set <string> AlbumsDB;
    set <string> SongsDB;

    // Display welcome message once per program execution
    cout << "Welcome to the Music Library App" << endl;
    cout << "--------------------------------" << endl;

    // Stay in menu until exit command
    do
    {
        cout << endl;
        cout << "Enter a command (help for help): " << endl;
        getline(cin, userEntry);
        cout << endl;

        // Split the user entry into two pieces
        splitFirstWord(userEntry, command, remains);
        tolower(command);

        // take an action, one per iteration, based on the command
        if (command == "help")
        {
            helpCommand();
        }
        else if (command == "clear")
        {
            ArtistsDB.clear();
            SongsDB.clear();
            AlbumsDB.clear();
            Albums.clear();
            Artists.clear();
        }
        else if (command == "export")
        {
            expo(Albums, Artists, remains);
        }
        else if (command == "load")
        {
            load(Albums, Artists, ArtistsDB, AlbumsDB, SongsDB, remains);
        }
        else if (command == "stats")
        {
            stats(Albums, Artists, ArtistsDB, AlbumsDB, SongsDB, remains);
        }
        else if (command == "search")
        {
            // TODO
        }

    }while(command != "exit");

    cout << "Thank you for using the Music Library App" << endl;
    return 0;
}
