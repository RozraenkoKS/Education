#include <iostream>
#include <filesystem>
#include <boost/algorithm/string.hpp>

void filenames_touppercase(std::filesystem::path path, bool uppercase) {
    for (const auto& entry: 
         std::filesystem::directory_iterator(path)) {

        auto old_path { entry.path() };
        auto old_name { old_path.filename().string() };
        auto new_name { old_name };

        if (uppercase) {
            boost::to_upper(new_name);
        }
        else {
            boost::to_lower(new_name);
        }

        auto new_path { old_path };
        new_path.replace_filename(new_name);

        if (old_path != new_path) {
			std::cout << old_path.string() << " --> "
				<< new_path.string() << '\n';

			if (std::filesystem::exists(new_path)) {
				std::cerr << "Error: Can't rename."
					" Destination file exists.\n";
			}
			else {
				std::filesystem::rename(old_path, new_path);
			}

		}
    }
}

int main() {
    filenames_touppercase(std::filesystem::current_path(), true);
    return 0;
}