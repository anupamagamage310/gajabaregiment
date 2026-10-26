#pragma once
#include <string>

namespace FasFlix {
    class StringHelper {
    public:
        static std::string ToStd(System::String^ s) {
            if (s == nullptr) return "";
            System::IntPtr ptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(s);
            std::string result = static_cast<const char*>(ptr.ToPointer());
            System::Runtime::InteropServices::Marshal::FreeHGlobal(ptr);
            return result;
        }

        static System::String^ ToManaged(const std::string& s) {
            return gcnew System::String(s.c_str());
        }
    };

    inline std::string ToStdString(System::String^ s) {
        return StringHelper::ToStd(s);
    }

    inline System::String^ ToManagedString(const std::string& s) {
        return StringHelper::ToManaged(s);
    }
}
