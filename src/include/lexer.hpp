#ifndef LEXER_HPP
#define LEXER_HPP
enum class ReservedToken : std::uint8_t
{
    Unknown,

    OpParenthesisOpen,
    OpParenthesisClose,
    OpSubscriptOpen,
    OpSubscriptClose,
    OpMod,
    OpAssignMod,
    OpLogicalNot,
    OpNotEqual,
    OpAdd,
    OpDiv,
    OpExp,
    OpBitwiseAnd,
    OpBitwiseOr,
    OpAssignBitwiseOr,
    OpLogicalOr,
    OpBitwiseNot,

    // ... the rest of the operators

    // Keywords
    KwBreak,
    KwClass,
    KwContinue,
    Kwstruct,
    KwFunc,
    KwDel,
    KwElif,
    KwElse,
    KwImport,
    KwFrom,
    KwFor,
    KwWile,
    KwSwitch,
    KwFalse,
    KwTrue,
    KwExit,
    KwIf,
    // ... the rest of the keywords

    // Number of possible reserved tokens
    Functions,
    Count
};
struct StringifiedToken
{
    std::string_view tokenStr;
    ReservedToken    token{ ReservedToken::Unknown };

    [[ nodiscard ]]
    constexpr bool operator<( StringifiedToken const & rhs ) const
    {
        return tokenStr < rhs.tokenStr;
    }
};
template< typename T, std::size_t N >
[[ nodiscard ]]
constexpr std::array< T, N > sort( std::array< T, N > arr ) noexcept
{
    std::sort( std::begin( arr ), std::end( arr ) );
    return arr;
}

constexpr std::array keywords
{
    sort
    (
        std::array
        {
            StringifiedToken{ "false" , ReservedToken::KwFalse },
            StringifiedToken{ "true"  , ReservedToken::KwTrue },
            StringifiedToken{ "break"  , ReservedToken::KwBreak },
            StringifiedToken{ "class"  , ReservedToken::KwClass },
            StringifiedToken{ "break"  , ReservedToken::KwBreak },
            StringifiedToken{ "break"  , ReservedToken::KwBreak },
            StringifiedToken{ "break"  , ReservedToken::KwBreak },
            StringifiedToken{ "break"  , ReservedToken::KwBreak },
            StringifiedToken{ "break"  , ReservedToken::KwBreak },
            StringifiedToken{ "break"  , ReservedToken::KwBreak },
            StringifiedToken{ "break"  , ReservedToken::KwBreak },
            StringifiedToken{ "break"  , ReservedToken::KwBreak },
            StringifiedToken{ "break"  , ReservedToken::KwBreak },
            StringifiedToken{ "break"  , ReservedToken::KwBreak },
            StringifiedToken{ "break"  , ReservedToken::KwBreak },
            StringifiedToken{ "break"  , ReservedToken::KwBreak },
            StringifiedToken{ "break"  , ReservedToken::KwBreak },
            StringifiedToken{ "break"  , ReservedToken::KwBreak },
            StringifiedToken{ "break"  , ReservedToken::KwBreak },
            StringifiedToken{ "break"  , ReservedToken::KwBreak },
            StringifiedToken{ "break"  , ReservedToken::KwBreak },
            StringifiedToken{ "break"  , ReservedToken::KwBreak },
            
            // ... the rest of the mappings
            StringifiedToken{ "exit" , ReservedToken::KwExit }
        }
    )
};

constexpr auto operators
{
    sort
    (
        std::array
        {
            StringifiedToken{ "!"  , ReservedToken::OpLogicalNot },
            StringifiedToken{ "!=" , ReservedToken::OpNotEqual },
            StringifiedToken{ "%"  , ReservedToken::OpMod },
            StringifiedToken{ "%=" , ReservedToken::OpAssignMod },

            // ... the rest of the mappings

            StringifiedToken{ "&"  , ReservedToken::OpBitwiseAnd },
            StringifiedToken{ "|"  , ReservedToken::OpBitwiseOr },
            StringifiedToken{ "|=" , ReservedToken::OpAssignBitwiseOr },
            StringifiedToken{ "||" , ReservedToken::OpLogicalOr },
            StringifiedToken{ "~"  , ReservedToken::OpBitwiseNot }
        }
    )
};
#endif // LEXER_HPP
